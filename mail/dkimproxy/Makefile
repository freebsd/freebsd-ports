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

BUILD_DEPENDS=	p5-Mail-DKIM>=0:${PORTSDIR}/mail/p5-Mail-DKIM \
		p5-Net-Server>=0:${PORTSDIR}/net/p5-Net-Server \
		p5-Error>=0:${PORTSDIR}/lang/p5-Error
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	IPV6

GNU_CONFIGURE=	yes
USES=		perl5
NO_ARCH=	yes
USE_RC_SUBR=	dkimproxy_in dkimproxy_out

DKIMPROXYUSER=	dkimproxy
USERS=		${DKIMPROXYUSER}
GROUPS=		${DKIMPROXYUSER}

SUB_LIST+=	PERL=${PERL} \
		DKIMPROXYUSER=${DKIMPROXYUSER}

IPV6_RUN_DEPENDS=	p5-IO-Socket-INET6>=0:${PORTSDIR}/net/p5-IO-Socket-INET6

IPV6_EXTRA_PATCHES=	${FILESDIR}/extra-patch-lib-MSDW-SMTP-Server.pm
IPV6_EXTRA_PATCHES=	${FILESDIR}/extra-patch-scripts-dkimproxy.out
IPV6_EXTRA_PATCHES=	${FILESDIR}/extra-patch-scripts-dkimproxy_in.conf.example
IPV6_EXTRA_PATCHES=	${FILESDIR}/extra-patch-scripts-dkimproxy_out.conf.example

post-patch:
	@${GREP} -Ril 'perl' ${WRKDIR} | ${XARGS} ${REINPLACE_CMD} -i '' \
		-e 's|/usr/bin/perl|${PERL}|' -e 's|@PERL@|${PERL}|'

.include <bsd.port.mk>
