# New ports collection makefile for:   smartmontools
# Date created:        12 October 2003
# Whom:                Eduard Martinescu
#
# $FreeBSD$
#

PORTNAME=	smartmontools
PORTVERSION=	5.36
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	martines@rochester.rr.com
COMMENT=	S.M.A.R.T. disk monitoring tools

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-initscriptdir=${PREFIX}/etc/rc.d \
		--with-docdir=${DOCSDIR} --enable-sample
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

SUB_FILES=	pkg-message
USE_RC_SUBR=	smartd

PROGRAMS=	smartctl smartd
MAN5=		smartd.conf.5
MAN8=		smartd.8 smartctl.8
DOCS=		AUTHORS CHANGELOG INSTALL NEWS README TODO WARNINGS
EXAMPLES=	smartd.conf examplescripts/README examplescripts/Example?

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PROGRAMS} ${PREFIX}/sbin
	cd ${WRKSRC} && ${INSTALL_MAN} ${MAN5} ${MANPREFIX}/man/man5
	cd ${WRKSRC} && ${INSTALL_MAN} ${MAN8} ${MANPREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/smartd.conf.sample ${PREFIX}/etc
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
