# $FreeBSD$

.SUFFIXES:	.bdf .pcf.gz

STEMS:=	italic09 italic12 roman09 roman10 roman12
PCFS:=	${STEMS:S/$/.pcf.gz/}

all:	${PCFS} fonts.dir fonts.alias

.bdf.pcf.gz:
	${X11BASE}/bin/bdftopcf < $< | gzip -9 > $@

fonts.dir: ${PCFS}
	${X11BASE}/bin/mkfontdir

# I don't know why ``isoir-111'' was  chosen for this fonts' encoding --
# they  are in  koi8-u, so  the each  will have  a corresponding  alias.
# Ukrainian koi8-u  is a  superset of  Russian koi8-r,  for applications
# that hardcode koi8-r in them, but omit koi8-u -- there will be another
# alias:
fonts.alias: fonts.dir
	awk '/monaco/ { \
		name = $$2; gsub("isoir-111", "koi8-u", $$2); \
		print $$2 " " name; gsub("koi8-u", "koi8-r", $$2); \
		print $$2 " " name}' < fonts.dir > fonts.alias

DIR=	${X11BASE}/lib/X11/fonts/koi8u-monaco

install: all
	${MKDIR} ${DIR}
	${INSTALL_DATA} ${PCFS} fonts.dir fonts.alias ${DIR}
