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
COMMENT=	Lot of funny Polish fortune files

BROKEN=		unfetchable

.if exists(/usr/games/strfile)
STRCMD=		/usr/games/strfile
.elif exists(/usr/bin/strfile)
STRCMD=		/usr/bin/strfile
.else
IGNORE=		needs strfile command. Please install games distribution of base system
.endif
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

do-patch:
	${CP} ${DISTDIR}/fortunes-pl_${PORTVERSION}.freebsd.pl ${WRKSRC}/freebsd.pl
	${CP} ${DISTDIR}/fortunes-pl_${PORTVERSION}.filozofia ${WRKSRC}/filozofia

do-build:
.for FILE in ${FORTUNES}
	@${STRCMD} ${WRKSRC}/${FILE}
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games/fortune/pl
.for FILE in ${FORTUNES}
	${INSTALL_DATA} ${WRKSRC}/${FILE} \
		${STAGEDIR}${PREFIX}/share/games/fortune/pl
	${INSTALL_DATA} ${WRKSRC}/${FILE}.dat \
		${STAGEDIR}${PREFIX}/share/games/fortune/pl
.endfor

.include <bsd.port.mk>
