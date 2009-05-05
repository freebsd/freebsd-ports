# New ports collection makefile for:   monit
# Date created:        4 January 2005
# Whom:                Martin Pala <martinp@tildeslash.com>
#
# $FreeBSD$
#

PORTNAME=	monit
PORTVERSION=	5.0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.mmonit.com/monit/dist/

MAINTAINER=	martinp@tildeslash.com
COMMENT=	Unix system management and monitoring

MAN1=		monit.1

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BISON=	build
USE_RC_SUBR=	monit.sh

CONFIGURE_ENV=	CC="${CC}" CPPFLAGS="${CPPFLAGS}" \
		CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}" CONFIG_SHELL="${SH}" \
		LOCALBASE="${LOCALBASE}"

OPTIONS=	SSL "Enable SSL support" on \
		RESOURCE "Enable resource support (not for jail)" on

PLIST_FILES=	bin/monit \
		etc/monitrc.sample

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if defined(WITH_SSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--enable-ssl --with-openssl="${OPENSSLBASE}"
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if defined(WITH_RESOURCE)
CONFIGURE_ARGS+=	--with-resource
.else
CONFIGURE_ARGS+=	--without-resource
.endif

post-install:
	${INSTALL_SCRIPT} -m 600 ${WRKDIR}/${DISTNAME}/monitrc ${PREFIX}/etc/monitrc.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_SCRIPT} -m 644 ${WRKDIR}/${DISTNAME}/CHANGES.txt ${PREFIX}/share/doc/monit/CHANGES.txt
	${INSTALL_SCRIPT} -m 644 ${WRKDIR}/${DISTNAME}/CONTRIBUTORS ${PREFIX}/share/doc/monit/CONTRIBUTORS
	${INSTALL_SCRIPT} -m 644 ${WRKDIR}/${DISTNAME}/FAQ.txt ${PREFIX}/share/doc/monit/FAQ.txt
	${INSTALL_SCRIPT} -m 644 ${WRKDIR}/${DISTNAME}/LICENSE ${PREFIX}/share/doc/monit/LICENSE
	${INSTALL_SCRIPT} -m 644 ${WRKDIR}/${DISTNAME}/README ${PREFIX}/share/doc/monit/README
	${INSTALL_SCRIPT} -m 644 ${WRKDIR}/${DISTNAME}/README.SSL ${PREFIX}/share/doc/monit/README.SSL
	${INSTALL_SCRIPT} -m 644 ${WRKDIR}/${DISTNAME}/doc/examples.html ${PREFIX}/share/doc/monit/examples.html
	${INSTALL_SCRIPT} -m 644 ${WRKDIR}/${DISTNAME}/doc/monit.html ${PREFIX}/share/doc/monit/monit.html
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
