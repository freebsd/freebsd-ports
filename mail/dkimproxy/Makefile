# Created by: Yoshisato YANAGISAWA
# $FreeBSD$

PORTNAME=	dkimproxy
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	SF

MAINTAINER=	andrey@bsdnir.info
COMMENT=	DKIM filter for Postfix

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-Mail-DKIM>=0:mail/p5-Mail-DKIM \
		p5-Net-Server>=0:net/p5-Net-Server \
		p5-Error>=0:lang/p5-Error
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake perl5 shebangfix

USE_RC_SUBR=	dkimproxy_in dkimproxy_out
GNU_CONFIGURE=	yes
NO_ARCH=	yes
SHEBANG_FILES=	scripts/*

DKIMPROXYUSER=	dkimproxy
USERS=		${DKIMPROXYUSER}
GROUPS=		${DKIMPROXYUSER}

SUB_LIST+=	PERL=${PERL} \
		DKIMPROXYUSER=${DKIMPROXYUSER}

OPTIONS_DEFINE=	IPV6 TEST
OPTIONS_SUB=	yes

IPV6_RUN_DEPENDS=	p5-IO-Socket-INET6>=0:net/p5-IO-Socket-INET6

IPV6_EXTRA_PATCHES=	${FILESDIR}/extra-patch-lib_MSDW_SMTP_Server.pm \
			${FILESDIR}/extra-patch-scripts_dkimproxy.out \
			${FILESDIR}/extra-patch-scripts_dkimproxy__in.conf.example \
			${FILESDIR}/extra-patch-scripts_dkimproxy__out.conf.example

TEST_DESC=	Use dkim_responder.pl
TEST_RUN_DEPENDS=	p5-MIME-Tools>=0:mail/p5-MIME-Tools

.include <bsd.port.mk>
