# New ports collection makefile for:    ourmon
# Date created: 01 May 2005
# Whom:         Charlie Schluting <manos@cs.pdx.edu>
#
# $FreeBSD$

PORTNAME=	ourmon
PORTVERSION=	2.8.1
PORTREVISION=	7
CATEGORIES=	net-mgmt
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=${PORTNAME}/${PORTNAME}/${PORTNAME}281
DISTNAME=	ourmon281

MAINTAINER=	manos@cs.pdx.edu
COMMENT=	A libpcap-based network monitoring and anomaly detection system

BUILD_DEPENDS=	${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap \
		${LOCALBASE}/lib/libpcre.a:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	rrdtool:${PORTSDIR}/databases/rrdtool

WRKSRC=			${WRKDIR}/mrourmon
USES=			perl5
USE_APACHE_RUN=		22+
NO_BUILD=		yes
NO_INSTALL_MANPAGES=	yes
IS_INTERACTIVE=		yes

SUB_FILES=	pkg-message

USE_RC_SUBR=	ourmon

.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO_MSG} "==================================================="
	@${ECHO_MSG} "ATTENTION: Do not install startup script during"
	@${ECHO_MSG} "interactive steps, use the created by port instead."
	@${ECHO_MSG} "==================================================="

post-patch:
	@${REINPLACE_CMD} -e 's|%%WWWDIR%%|${WWWDIR}|g' ${WRKSRC}/configure.pl

do-install:
	@cd ${WRKSRC} && ${PERL5} configure.pl ${PREFIX}
	@${FIND} ${WRKSRC} \( -name '*.orig' -o -name '*.bak' -o -name '*.o' \) -delete
	@${CP} -R ${WRKSRC} ${PREFIX}

post-install:
	@${CAT} ${PKGMESSAGE}
.include <bsd.port.post.mk>
