# New ports collection makefile for:   monit
# Date created:        4 Januar 2005
# Whom:                Martin Pala <martinp@tildeslash.com>
#
# $FreeBSD$
#

PORTNAME=		monit
PORTVERSION=		4.4
CATEGORIES=		sysutils
MASTER_SITES=		http://www.tildeslash.com/monit/dist/

MAINTAINER=		martinp@tildeslash.com
COMMENT=		Unix system management and monitoring tool

MAN1=			monit.1

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_BISON=		yes
USE_RC_SUBR=		yes

CONFIGURE_ENV=		CC="${CC}" CPPFLAGS="${CPPFLAGS}" \
			CFLAGS="${CFLAGS}" \
			LDFLAGS="${LDFLAGS}" CONFIG_SHELL="${SH}" \
			LOCALBASE="${LOCALBASE}"

OPTIONS=		MONIT_SSL "Enable SSL support" on

PLIST_FILES=		bin/monit \
			etc/monitrc.sample \
			etc/rc.d/monit.sh \
			share/doc/monit/CHANGES.txt \
			share/doc/monit/CONTRIBUTORS \
			share/doc/monit/FAQ.txt \
			share/doc/monit/LICENSE \
			share/doc/monit/README \
			share/doc/monit/README.SSL \
			share/doc/monit/STATUS \
			share/doc/monit/examples.html \
			share/doc/monit/monit.html
PLIST_DIRS=		share/doc/monit

.include <bsd.port.pre.mk>

pre-install:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%RC_SUBR%%|${RC_SUBR}|g' \
		${FILESDIR}/monit.sh > ${WRKDIR}/monit.sh

post-install:
	@${INSTALL_SCRIPT} -m 755 ${WRKDIR}/monit.sh ${PREFIX}/etc/rc.d/monit.sh
	@${INSTALL_SCRIPT} -m 600 ${WRKDIR}/${DISTNAME}/monitrc ${PREFIX}/etc/monitrc.sample
	${MKDIR} ${DOCSDIR}
	@${INSTALL_SCRIPT} -m 644 ${WRKDIR}/${DISTNAME}/CHANGES.txt ${PREFIX}/share/doc/monit/CHANGES.txt
	@${INSTALL_SCRIPT} -m 644 ${WRKDIR}/${DISTNAME}/CONTRIBUTORS ${PREFIX}/share/doc/monit/CONTRIBUTORS
	@${INSTALL_SCRIPT} -m 644 ${WRKDIR}/${DISTNAME}/FAQ.txt ${PREFIX}/share/doc/monit/FAQ.txt
	@${INSTALL_SCRIPT} -m 644 ${WRKDIR}/${DISTNAME}/LICENSE ${PREFIX}/share/doc/monit/LICENSE
	@${INSTALL_SCRIPT} -m 644 ${WRKDIR}/${DISTNAME}/README ${PREFIX}/share/doc/monit/README
	@${INSTALL_SCRIPT} -m 644 ${WRKDIR}/${DISTNAME}/README.SSL ${PREFIX}/share/doc/monit/README.SSL
	@${INSTALL_SCRIPT} -m 644 ${WRKDIR}/${DISTNAME}/STATUS ${PREFIX}/share/doc/monit/STATUS
	@${INSTALL_SCRIPT} -m 644 ${WRKDIR}/${DISTNAME}/doc/examples.html ${PREFIX}/share/doc/monit/examples.html
	@${INSTALL_SCRIPT} -m 644 ${WRKDIR}/${DISTNAME}/doc/monit.html ${PREFIX}/share/doc/monit/monit.html
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} "	${PREFIX}/etc/monitrc.sample"
	@${ECHO_MSG} "	${PREFIX}/share/doc/monit/examples.html"

.if defined(WITH_MONIT_SSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--enable-ssl \
			--with-openssl="${OPENSSLBASE}"
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.include <bsd.port.post.mk>
