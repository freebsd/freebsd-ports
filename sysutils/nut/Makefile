# New ports collection makefile for:    nut
# Date created:         08 Jan 2000
# Whom:                 Boris Popov <bp@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	nut
PORTVERSION=	0.44.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.exploits.org/nut/release/

MAINTAINER=	bp@butya.kz

.if defined(CGI)
LIB_DEPENDS=    gd:${PORTSDIR}/graphics/gd
.endif

GNU_CONFIGURE=  yes
CONFIGURE_ARGS= --sysconfdir=${PREFIX}/etc/nut \
		--with-cgipath=${PREFIX}/share/nut/cgi \
		--with-modelpath=${PREFIX}/sbin \
		--with-uid=65534 --with-gid=68 

ALL_TARGET=	all

PLIST=	${WRKDIR}/PLIST.DYN

NDOCDIR=	${PREFIX}/share/doc/nut

.if defined(CGI)
NCGIDIR=	${PREFIX}/share/nut/cgi
ALL_TARGET+=	cgi
.endif

pre-fetch:
.if !defined(CGI)
	@${ECHO_MSG} "Type \"make CGI=yes\" if you want to build CGI scripts."
.endif

pre-install:
	@cp ${PKGDIR}/PLIST ${WRKDIR}/PLIST.DYN
.if !defined(NOPORSDOCS)
	@cat ${PKGDIR}/PLIST.DOC >> ${WRKDIR}/PLIST.DYN
.endif
.if defined(CGI)
	@cat ${PKGDIR}/PLIST.CGI >> ${WRKDIR}/PLIST.DYN
.endif

post-install:
	@${SED} -e "/%%PREFIX%%/s##${PREFIX}#g" \
		${WRKSRC}/scripts/FreeBSD/upsd.sh.sample \
		>${PREFIX}/etc/rc.d/upsd.sh.sample
	@${CHMOD} 0755 ${PREFIX}/etc/rc.d/upsd.sh.sample
.if !defined(NOPORTDOCS)
	@if ! [ -d ${NDOCDIR} ]; then ${MKDIR} ${NDOCDIR}; fi
	@if ! [ -d ${NDOCDIR}/cables ]; then ${MKDIR} ${NDOCDIR}/cables; fi
	${INSTALL_DATA} ${WRKSRC}/docs/cables/*.txt ${NDOCDIR}/cables
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${NDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ ${NDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/Changes.trust ${NDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${NDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/QUICKSTART ${NDOCDIR}
.endif
.if defined(CGI)
	@if ! [ -d ${NCGIDIR} ]; then ${MKDIR} ${NCGIDIR}; fi
	${INSTALL_DATA} ${WRKSRC}/clients/*.cgi ${NCGIDIR}
	@${ECHO_MSG} "Look in ${NCGIDIR} for cgi scripts."
.endif
	@${ECHO_MSG} "Look in ${NDOCDIR} for documentation."

.include <bsd.port.mk>
