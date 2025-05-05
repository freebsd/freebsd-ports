# https://joeldare.com/rounding-image-corners-with-imagemagick
rounded_corners()
{
	local destdir height mask radius ratio subdir t0 width

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

			echo -n "Generating flags ${width}x${height}... "
			t0=$(date +%s)
			for flag in $subdir/*.svg; do
				convert -resize ${width}x${height} \
				"$flag" -matte "$mask" \
				-compose DstIn -composite -strip \
				"$destdir/${width}x${height}/$(basename "$flag" svg)png"
			done
			echo "finished in $(date -ur $((`date +%s`-t0)) +%M:%S)"
		done
	done
	rm "$mask"
}

"$@"
