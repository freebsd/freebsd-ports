# New ports collection makefile for:	dkimproxy
# Date created:				16 July 2006
# Whom:					Yoshisato YANAGISAWA
#
# $FreeBSD$
#

PORTNAME=	dkimproxy
PORTVERSION=	1.4.1
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	yanagisawa@csg.is.titech.ac.jp
COMMENT=	DKIM filter for Postfix

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-Mail-DKIM>=0:${PORTSDIR}/mail/p5-Mail-DKIM \
		p5-Net-Server>=0:${PORTSDIR}/net/p5-Net-Server \
		p5-Error>=0:${PORTSDIR}/lang/p5-Error
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USES=		perl5
USE_RC_SUBR=	dkimproxy_in dkimproxy_out

DKIMPROXYUSER=	dkimproxy
USERS=		${DKIMPROXYUSER}
GROUPS=		${DKIMPROXYUSER}

MAN8=		dkimproxy_in.8 dkimproxy_out.8

SUB_LIST+=	PERL=${PERL} \
		DKIMPROXYUSER=${DKIMPROXYUSER}

post-patch:
	@${GREP} -Ril 'perl' ${WRKDIR} | ${XARGS} ${REINPLACE_CMD} -i '' \
		-e 's|/usr/bin/perl|${PERL}|' -e 's|@PERL@|${PERL}|'

.include <bsd.port.mk>
