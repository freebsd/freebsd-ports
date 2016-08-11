# Created by: Evaldas Auryla <ea@zaib.as>
# $FreeBSD$

PORTNAME=	digitemp
PORTVERSION=	3.6.0
CATEGORIES=	misc
MASTER_SITES=	http://www.digitemp.com/software/linux/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dallas Semiconductor 1-wire device reading console application

LICENSE=	GPLv2

USES=		gmake
MAKE_ARGS+=	CC="${CC}"

PLIST_FILES=	bin/digitemp_DS9097 bin/digitemp_DS9097U \
		etc/digitemp.conf.sample \
		man/man1/digitemp.1.gz

DOCFILES=	ChangeLog COPYRIGHT CREDITS FAQ README TODO \
		dthowto.txt DS9097_Schematic.gif
DOCDIRS=	perl python rrdb
PORTDOCS=	${DOCFILES} ${DOCDIRS}

ALL_TARGET=	ds9097 ds9097u

OPTIONS_DEFINE=	DOCS

pre-install:
	${REINPLACE_CMD} -e "s/dev\/ttyS/dev\/cuau/g" ${WRKSRC}/${PORTNAME}.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/digitemp_DS9097 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/digitemp_DS9097U ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${FILESDIR}/digitemp.conf.sample ${STAGEDIR}${PREFIX}/etc/
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Sample config installed at ${PREFIX}/etc/digitemp.conf.sample"
	@${ECHO_MSG} ""

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCFILES:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.for dir in perl python/gui python/mysql rrdb
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/${dir}
	${FIND} ${WRKSRC}/${dir}/ -maxdepth 1 -type f -exec ${INSTALL_DATA} \{\} ${STAGEDIR}${DOCSDIR}/${dir} \;
.endfor

.include <bsd.port.mk>
