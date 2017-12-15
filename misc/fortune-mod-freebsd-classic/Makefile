# $FreeBSD$

PORTNAME=	fortune-mod-freebsd-classic
DISTVERSION=	g20171128
CATEGORIES=	misc

MAINTAINER=	jdc@koitsu.org
COMMENT=	Classic FreeBSD fortunes (including offensives)

# LICENSE is intentionally unset.  Some fortune files, such as
# gerrold.limerick, are copyright the author but used with permission.
# Others have no license defined in them.  I get the impression many
# are Public Domain or possibly BSD4CLAUSE -- consider fortune was
# originally written by Ken Arnold at UC Berkeley; the FreeBSD
# fortune import was from 4.4BSD-Lite circa 1995.

USE_GITHUB=	yes
GH_ACCOUNT=	koitsu
GH_TAGNAME=	b029e87
NO_ARCH=	yes

SRCF=		fortunes fortunes-o gerrold.limerick limerick murphy murphy-o startrek zippy
PLIST_FILES=	${SRCF:S|^|share/games/fortune/|} ${SRCF:S|^|share/games/fortune/|:S|$|.dat|}

.if exists(/usr/games/strfile)
_STRFILE=	/usr/games/strfile
.elif exists(/usr/bin/strfile)
_STRFILE=	/usr/bin/strfile
.else
IGNORE=		needs strfile command. Please install games distribution of base system
.endif

do-build:
.for f in ${SRCF}
	@${_STRFILE} -Cs ${WRKSRC}/datfiles/${f} ${WRKSRC}/datfiles/${f}.dat
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games/fortune
.for f in ${SRCF}
	${INSTALL_DATA} ${WRKSRC}/datfiles/${f} ${WRKSRC}/datfiles/${f}.dat ${STAGEDIR}${PREFIX}/share/games/fortune
.endfor

.include <bsd.port.mk>
