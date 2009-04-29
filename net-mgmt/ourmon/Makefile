# New ports collection makefile for:    ourmon
# Date created: 01 May 2005
# Whom:         Charlie Schluting <manos@cs.pdx.edu>
#
# $FreeBSD$

PORTNAME=	ourmon
PORTVERSION=	2.8.1
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	SF
DISTNAME=	ourmon281

MAINTAINER=	manos@cs.pdx.edu
COMMENT=	A libpcap-based network monitoring and anomaly detection system

BUILD_DEPENDS=	${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap \
		${LOCALBASE}/lib/libpcre.a:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	rrdtool:${PORTSDIR}/databases/rrdtool

WRKSRC=			${WRKDIR}/mrourmon
USE_APACHE=		1.3
USE_PERL5=		yes
NO_BUILD=		yes
NO_INSTALL_MANPAGES=	yes

SUB_FILES=	pkg-message

USE_RC_SUBR=	ourmon

.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO_MSG} "==================================================="
	@${ECHO_MSG} "ATTENTION: Do not install startup script during"
	@${ECHO_MSG} "interactive steps, use the created by port instead."
	@${ECHO_MSG} "==================================================="

do-install:
	@cd ${WRKSRC} && ${PERL5} configure.pl ${PREFIX}
	@${CP} -R ${WRKSRC} ${PREFIX}

post-install:
	@${CAT} ${PKGMESSAGE}
.include <bsd.port.post.mk>
