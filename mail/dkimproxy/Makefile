# Created by: Yoshisato YANAGISAWA
# $FreeBSD$

PORTNAME=	dkimproxy
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	SF

MAINTAINER=	andrey@bsdnir.info
COMMENT=	DKIM filter for Postfix

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-Mail-DKIM>=0:mail/p5-Mail-DKIM \
		p5-Net-Server>=0:net/p5-Net-Server \
		p5-Error>=0:lang/p5-Error
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	IPV6 TEST
OPTIONS_SUB=	yes

GNU_CONFIGURE=	yes
USES=		perl5 shebangfix
SHEBANG_FILES=	scripts/*
NO_ARCH=	yes
USE_RC_SUBR=	dkimproxy_in dkimproxy_out

DKIMPROXYUSER=	dkimproxy
USERS=		${DKIMPROXYUSER}
GROUPS=		${DKIMPROXYUSER}

SUB_LIST+=	PERL=${PERL} \
		DKIMPROXYUSER=${DKIMPROXYUSER}

IPV6_RUN_DEPENDS=	p5-IO-Socket-INET6>=0:net/p5-IO-Socket-INET6

IPV6_EXTRA_PATCHES=	${FILESDIR}/extra-patch-lib-MSDW-SMTP-Server.pm \
			${FILESDIR}/extra-patch-scripts-dkimproxy.out \
			${FILESDIR}/extra-patch-scripts-dkimproxy_in.conf.example \
			${FILESDIR}/extra-patch-scripts-dkimproxy_out.conf.example

TEST_DESC=	Use dkim_responder.pl
TEST_RUN_DEPENDS=	p5-MIME-Tools>=0:mail/p5-MIME-Tools

.include <bsd.port.mk>
