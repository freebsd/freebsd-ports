# New ports collection makefile for:	munin-node
# Date created:				25 Januar 2004
# Whom:					Lupe Christoph <lupe@lupe-christoph.de>
#
# $FreeBSD$
#

PORTNAME=	munin
PORTVERSION=	1.2.6
PORTREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	munin
PKGNAMESUFFIX=	-node
DISTNAME=	${PORTNAME}_${PORTVERSION:S/.r/rc/}

MAINTAINER=	des@FreeBSD.org
COMMENT=	Node-specific part of Munin

USE_PERL5=	yes

RUN_DEPENDS=	${SITE_PERL}/Net/Server/Fork.pm:${PORTSDIR}/net/p5-Net-Server
BUILD_DEPENDS=	${RUN_DEPENDS}

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.r/rc/}
PKGMESSAGE=	${WRKDIR}/pkg-message
ALL_TARGET=	WWWDIR=${WWWDIR} DATADIR=${DATADIR} PERL=${PERL} build build-man
INSTALL_TARGET=	WWWDIR=${WWWDIR} DATADIR=${DATADIR} PERL=${PERL} SITE_PERL_REL=$(SITE_PERL_REL) install-node install-node-plugins
MAKE_ENV=	LANG=C

MAN5=		munin-node.conf.5
MAN8=		munin-node-configure.8 munin-node.8 munin-run.8

SUB_FILES=	pkg-message munin-node.sh munin-node-revive.sh
SUB_LIST=	RC_SUBR=${RC_SUBR}
USE_RC_SUBR=	YES

pre-su-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/munin-node.sh ${PREFIX}/etc/rc.d/munin-node.sh
	${INSTALL_DATA} ${WRKSRC}/build/node/munin-node.conf ${PREFIX}/etc/munin/munin-node.conf.sample
	${INSTALL_DATA} ${FILESDIR}/plugins.conf ${PREFIX}/etc/munin/plugin-conf.d/plugins.conf.sample
	@if [ ! -f ${PREFIX}/etc/munin/plugin-conf.d/plugins.conf ]; then \
		${INSTALL_DATA} ${PREFIX}/etc/munin/plugin-conf.d/plugins.conf.sample ${PREFIX}/etc/munin/plugin-conf.d/plugins.conf; \
	fi
	@${CAT} ${PKGMESSAGE}
	@${INSTALL_MAN} -C ${WRKSRC}/build/doc/munin-node.conf.5 ${PREFIX}/man/man5
	@${INSTALL_MAN} -C ${WRKSRC}/build/doc/munin-node-configure.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} -C ${WRKSRC}/build/doc/munin-node.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} -C ${WRKSRC}/build/doc/munin-run.8 ${PREFIX}/man/man8
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO} ${DISTNAME} | ${SED} -e 's/munin_//' > ${PREFIX}/etc/munin/VERSION.node

.include <bsd.port.mk>
