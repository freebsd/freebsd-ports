# https://commons.wikimedia.org/wiki/File:Flag_of_Esperanto.svg
add-esperanto-flag()
{
	cat > "$1/epo.svg" << EOD
<?xml version="1.0" encoding="UTF-8"?>
<svg xmlns="http://www.w3.org/2000/svg" width="$2" height="400">
<path fill="#FFF" d="m0,0h202v202H0"/>
<path fill="#090" d="m0,200H200V0H$2V400H0m58-243 41-126 41,126-107-78h133"/>
</svg>
EOD
}

add-missing-flags()
{
	add-esperanto-flag 1x1 400
	add-esperanto-flag 4x3 533
}

async() { "$@" & }

simple()
{
	local comment convert_extra_args destdir flag height i=0 ratio subdir t0 width

	comment=$1; convert_extra_args=$2; destdir=$3; shift 3

	for subdir in ?x?; do
		ratio=${subdir%x*}/${subdir#*x}
		for height; do
			width=$((height * $ratio))
			mkdir -p "$destdir/${width}x${height}"
			echo -n "Generating $comment flags ${width}x${height}... "
			t0=$(date +%s)
			for flag in $subdir/*.svg; do
				i=$((i % ${JOBS:-1}))
				test $((i+=1)) -eq 1 && wait
				async convert -resize ${width}x${height} $convert_extra_args \
				"$flag" "$destdir/${width}x${height}/$(basename "$flag" svg)png"
			done; wait
			echo "finished in $(date -ur $((`date +%s`-t0)) +%M:%S)"
		done
	done
}

plain()
{
	simple undecorated -strip "$@"
}

bordered()
{
	simple black-bordered '-shave 1x1 -bordercolor black -border 1 -strip' "$@"
}

# https://joeldare.com/rounding-image-corners-with-imagemagick
rounded()
{
	local destdir flag height i=0 mask radius ratio subdir t0 width

	destdir=$1; shift
	mask=$(mktemp)

	for subdir in ?x?; do
		ratio=${subdir%x*}/${subdir#*x}
		for height; do
			width=$((height * $ratio))
			radius=$((height / 10))

			convert -size ${width}x${height} xc:none -draw \
			"roundRectangle 0,0,$((width-1)),$((height-1)),$radius,$radius" \
			-strip "png:$mask"

			mkdir -p "$destdir/${width}x${height}"

			echo -n "Generating rounded corner flags ${width}x${height}... "
			t0=$(date +%s)
			for flag in $subdir/*.svg; do
				i=$((i % ${JOBS:-1}))
				test $((i+=1)) -eq 1 && wait
				async convert -resize ${width}x${height} \
				"$flag" -matte "$mask" \
				-compose DstIn -composite -strip \
				"$destdir/${width}x${height}/$(basename "$flag" svg)png"
			done; wait
			echo "finished in $(date -ur $((`date +%s`-t0)) +%M:%S)"
		done
	done
	rm "$mask"
}

"$@"
