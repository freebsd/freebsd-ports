# New ports collection makefile for:	mars_nwe
# Date created:		29 Dec 1998
# Whom:			Boris Popov <bp@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mars_nwe
PORTVERSION=	0.99.b19
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://www.compu-art.de/mars_nwe/ \
		ftp://ftp.gwdg.de/pub/linux/misc/ncpfs/mars_nwe/ \
		ftp://ftp.butya.kz/pub/mars_nwe/
DISTNAME=	mars_nwe-0.99.pl19
EXTRACT_SUFX=	.tgz

MAINTAINER=	bp@FreeBSD.org
COMMENT=	Netware server emulator for Un*x systems

WRKSRC=		${WRKDIR}/mars_nwe
MAKE_ENV=	CC="${CC}"

PLIST=	${WRKDIR}/PLIST.DYN

NDOCDIR=	${PREFIX}/share/doc/mars_nwe

do-install:
	@(cd ${WRKSRC} && ./mk.li install)
	@${INSTALL_DATA} ${WRKSRC}/examples/nw.ini ${PREFIX}/etc/nwserv.conf.example
	@${ECHO} "Please read details in ${WORKDIR}/mars_nwe/doc directory."

pre-install:
	@cp ${PKGDIR}/pkg-plist ${WRKDIR}/PLIST.DYN
.if !defined(NOPORSDOCS)
	@cat ${PKGDIR}/pkg-plist.DOC >> ${WRKDIR}/PLIST.DYN
.endif

post-install:
	@${SED} -e "/%%PREFIX%%/s##${PREFIX}#g" \
		${FILESDIR}/nwserv.sh \
		>${PREFIX}/etc/rc.d/nwserv.sh
	@${CHMOD} 0755 ${PREFIX}/etc/rc.d/nwserv.sh
.if !defined(NOPORTDOCS)
	@if ! [ -d ${NDOCDIR} ]; then ${MKDIR} ${NDOCDIR}; fi
	${RM} -f ${WRKSRC}/doc/*.orig
	${INSTALL_DATA} ${WRKSRC}/doc/* ${NDOCDIR}
.endif
	@${ECHO_MSG} "Look in ${NDOCDIR} for documentation."

.include <bsd.port.mk>
