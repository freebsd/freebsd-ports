# New ports collection makefile for:   qjail
# Date created:        July 22 2010
# Whom:                Joe Barbish
#
# $FreeBSD$

PORTNAME=	qjail
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	qjail@a1poweruser.com
COMMENT=	Utility to quickly deploy and manage large numbers of jails

LICENSE=	BSD

USE_BZIP2=	yes
NO_BUILD=	yes

MAN8=		qjail.8 qjail-intro.8 qjail.conf.8

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} \
		-e 's|/usr/local|${PREFIX}|'
	@${FIND} ${WRKSRC}/examples -name '*.bak' -delete

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/qjail ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/qjail2 ${PREFIX}/etc/rc.d
	@${INSTALL_SCRIPT} ${WRKSRC}/qjail-jail2 ${PREFIX}/etc/rc.d
	@${INSTALL_DATA}   ${WRKSRC}/qjail.conf.sample ${PREFIX}/etc
	@${INSTALL_MAN}    ${WRKSRC}/qjail.8 ${MAN8PREFIX}/man/man8
	@${INSTALL_MAN}    ${WRKSRC}/qjail-intro.8 ${MAN8PREFIX}/man/man8
	@${INSTALL_MAN}    ${WRKSRC}/qjail.conf.8 ${MAN8PREFIX}/man/man8
# note examples are mandatory. qjail will not function without them
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ \
	    && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
