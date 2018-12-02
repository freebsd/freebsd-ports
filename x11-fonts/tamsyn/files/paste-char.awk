BEGIN {
	char = copy
	found = 0
	lineslen = 1
	paste = 0
	prevchar = -1
}

paste {
	if ($1 == "CHARS") {
		printf "CHARS %s\n", $2 + 1
	} else {
		print
	}
}


/^STARTCHAR/, /^ENDCHAR/ {
	if (!paste) {
		lines[lineslen++] = $0
	}
}

$1 == "ENCODING" {
	if ($2 == char) {
		found = 1
		char = prevchar
	}
	prevchar = $2
}

$1 == "ENDCHAR" {
	if (paste && found) {
		print ""
		for (i = 1; i < lineslen; i++) {
			print lines[i]
		}
		found = 0
	} else if (found) {
		paste = 1
		found = 0
		nextfile
	} else if (!paste) {
		lineslen = 1
		found = 0
	}
}
