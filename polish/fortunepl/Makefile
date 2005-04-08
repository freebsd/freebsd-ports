# New ports collection makefile for:   fortunepl
# Date created:        13-01-2005
# Whom:                Aleksander Fafula <alex@bsdguru.org>
#
# $FreeBSD$
#

PORTNAME=	fortunepl
PORTVERSION=	0.0.20050220
CATEGORIES=	polish
MASTER_SITES=	ftp://ftp.debian.org/debian/pool/main/f/fortunes-pl/ \
		http://www.bsdguru.org/fortunes/20050320/
DISTNAME=	fortunes-pl_${PORTVERSION}.orig

PATCH_SITES=	http://bsdguru.org/fortunes/20050320/
PATCHFILES=	freebsd.pl filozofia

MAINTAINER=	alex@bsdguru.org
COMMENT=	A lot of funny Polish fortune files

STRCMD=		/usr/games/strfile
WRKSRC=		${WRKDIR}/fortunes-pl-${PORTVERSION}.orig

FORTUNES=	7thguard advocacy apcoh argante bajki bok cnp cows \
		dowcipy dowcipy-feministyczne dowcipy-lepper dowcipy-naukowcy \
		dowcipy-niskopoziomowe dowcipy-szowinistyczne dwimc dzieci \
		filozofia freebsd.pl gra_polslowek haiku http icpusers imiona \
		ipv6.pl komputery konikbujany koscielne lcamtuf life matura \
		microsoft milosc misc nauka ospl ospl-ad perl polish_manpages \
		pratchett puchatek radio_maryja rywingate sad sapkowski \
		seneka sigpl sigvirus slownik spolem sport stachura \
		teleturnieje testnaosobowosc wierszyki wieza-pilot zen \
		znaki_zodiaku

pre-everything::
.if !exists(${STRCMD})
IGNORE=		need strfile command. Please install games distribution of base system
.endif

do-patch:
.for extras in ${PATCHFILES}
	@${CP} ${DISTDIR}/${extras} ${WRKSRC}/
.endfor

do-build:
.for FILE in ${FORTUNES}
	@${STRCMD} ${WRKSRC}/${FILE}
.endfor

do-install:
	@${MKDIR} ${PREFIX}/share/games
	@${MKDIR} ${PREFIX}/share/games/fortune
	@${MKDIR} ${PREFIX}/share/games/fortune/pl
.for FILE in ${FORTUNES}
	@${ECHO_CMD} "Installing ${FILE} into ${PREFIX}/share/games/fortune/pl/"
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/share/games/fortune/pl
	@${INSTALL_DATA} ${WRKSRC}/${FILE}.dat ${PREFIX}/share/games/fortune/pl
.endfor

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Usage:"
	@${ECHO_MSG} "/usr/games/fortune ${PREFIX}/share/games/fortune/pl/<category>"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
