# Created by: Evaldas Auryla <ea@zaib.as>
# $FreeBSD$

PORTNAME=	digitemp
PORTVERSION=	3.6.0
CATEGORIES=	misc
MASTER_SITES=	http://www.digitemp.com/software/linux/

MAINTAINER=	ea@zaib.as
COMMENT=	Dallas Semiconductor 1-wire device reading console application

LICENSE=	GPLv2

USES=		gmake
MAKE_ARGS+=	CC="${CC}"

MAN1=		digitemp.1
PLIST_FILES=	bin/digitemp_DS9097 bin/digitemp_DS9097U \
		etc/digitemp.conf.sample

DOCFILES=	ChangeLog COPYRIGHT CREDITS FAQ README TODO \
		dthowto.txt DS9097_Schematic.gif
DOCDIRS=	perl python rrdb
PORTDOCS=	${DOCFILES} ${DOCDIRS}

ALL_TARGET=	ds9097 ds9097u

OPTIONS_DEFINE=	DOCS

pre-install:
	${CP} ${WRKSRC}/${MAN1} ${WRKSRC}/digitemp.1.M
	${CAT} ${WRKSRC}/digitemp.1.M | ${SED} -e "s/dev\/ttyS/dev\/cuau/g" > ${WRKSRC}/${MAN1}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/digitemp_DS9097 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/digitemp_DS9097U ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCFILES:S,^,${WRKSRC}/,} ${DOCSDIR}
.for dir in perl python/gui python/mysql rrdb
	@${MKDIR} ${DOCSDIR}/${dir}
	${FIND} ${WRKSRC}/${dir}/ -maxdepth 1 -type f -exec ${INSTALL_DATA} \{\} ${DOCSDIR}/${dir} \;
.endfor
.endif
	${CAT} ${PKGMESSAGE}
	${INSTALL_DATA} ${FILESDIR}/digitemp.conf.sample ${PREFIX}/etc/
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Sample config installed at ${PREFIX}/etc/digitemp.conf.sample"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
