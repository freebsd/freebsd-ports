# Created by: Yoshisato YANAGISAWA
# $FreeBSD$

PORTNAME=	dkfilter
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://jason.long.name/dkfilter/

MAINTAINER=	yanagisawa@csg.is.titech.ac.jp
COMMENT=	Domainkeys filter for Postfix

BUILD_DEPENDS=	p5-Crypt-OpenSSL-RSA>=0:${PORTSDIR}/security/p5-Crypt-OpenSSL-RSA \
		p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-Server>=0:${PORTSDIR}/net/p5-Net-Server
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USES=		perl5
USE_RC_SUBR=	dkfilter_in dkfilter_out

USERS=		${DKFILTER_USERNAME}
GROUPS=		${DKFILTER_GROUPNAME}

DKFILTER_USERNAME?=	dkfilter
DKFILTER_GROUPNAME?=	${DKFILTER_USERNAME}

NO_STAGE=	yes
.include <bsd.port.mk>
