# New ports collection makefile for:	lmd
# Date created:		Thu May 2 11:20:06 CET 2002
# Whom:			Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	lmd
PORTVERSION=	0.8
CATEGORIES=	net sysutils
MASTER_SITES=	http://www.bsdshell.net/download/

MAINTAINER=	sysadmin@alexdupre.com

USE_REINPLACE=	YES
REINPLACE_ARGS=	#empty

MODULES=	ldd_http_module.so
DOCS=		INSTALL LICENSE README
PKGMESSAGE=	${WRKDIR}/pkg-message

MAKE_ENV+=	CPPFLAGS="-DPREFIX=\\\"${PREFIX}\\\""

post-build:
	@${REINPLACE_CMD} -e 's,%PREFIX%,${PREFIX},g' \
		${.CURDIR}/pkg-message.in > ${WRKDIR}/pkg-message

do-install:
	@${ECHO_CMD} "Installing files..."
	@${INSTALL_PROGRAM} ${WRKSRC}/lmd      ${PREFIX}/sbin/lmd
	@${INSTALL_SCRIPT}  ${FILESDIR}/lmd.sh ${PREFIX}/etc/rc.d/lmd.sh
	@${INSTALL_DATA}    ${WRKSRC}/lmd.conf ${PREFIX}/etc/lmd.conf.sample
.for f in ${MODULES}
	@${INSTALL_DATA} ${WRKSRC}/modules_check/${f} ${PREFIX}/lib/
.endfor
	@${CAT} ${PKGMESSAGE}

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
