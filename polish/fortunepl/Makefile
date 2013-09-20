# Created by: Aleksander Fafula <alex@bsdguru.org>
# $FreeBSD$

PORTNAME=	fortunepl
PORTVERSION=	0.0.20051022
CATEGORIES=	polish
MASTER_SITES=	http://www.bsdguru.org/fortunes/
DISTNAME=	fortunes-pl_${PORTVERSION}.orig

PATCH_SITES=	http://bsdguru.org/fortunes/
PATCHFILES=	fortunes-pl_${PORTVERSION}.freebsd.pl \
		fortunes-pl_${PORTVERSION}.filozofia

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lot of funny Polish fortune files

STRCMD=		/usr/games/strfile
WRKSRC=		${WRKDIR}/fortunes-pl-${PORTVERSION}.orig

FORTUNES=	7thguard advocacy apcoh argante bajki bok cnp cows \
		dowcipy dowcipy-feministyczne dowcipy-lepper dowcipy-naukowcy \
		dowcipy-niskopoziomowe dowcipy-szowinistyczne dwimc dzieci \
		filozofia freebsd.pl gra_polslowek haiku http icpusers imiona \
		ipv6.pl komputery konikbujany koscielne lcamtuf life matura \
		microsoft milosc misc nauka ospl ospl-ad perl polish_manpages \
		pratchett psy1 puchatek radio_maryja rywingate sad sapkowski \
		seneka sigpl sigvirus slownik spolem sport stachura stirlitz \
		teleturnieje testnaosobowosc wierszyki wieza-pilot zen \
		znaki_zodiaku

NO_STAGE=	yes
pre-everything::
.if !exists(${STRCMD})
IGNORE=		need strfile command. Please install games distribution of base system
.endif

do-patch:
	${CP} ${DISTDIR}/fortunes-pl_${PORTVERSION}.freebsd.pl ${WRKSRC}/freebsd.pl
	${CP} ${DISTDIR}/fortunes-pl_${PORTVERSION}.filozofia ${WRKSRC}/filozofia

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
