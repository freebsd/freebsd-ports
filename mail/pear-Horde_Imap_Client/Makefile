# $FreeBSD$

PORTNAME=	Horde_Imap_Client
PORTVERSION=	2.19.0
CATEGORIES=	mail www pear
PKGNAMEPREFIX=	pear-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde IMAP abstraction interface

USE_PHP=	hash
USE_HORDE_RUN=	Horde_Exception \
		Horde_Mail \
		Horde_Mime \
		Horde_Stream \
		Horde_Util

OPTIONS_DEFAULT=	IMAP MBSTRING SASL
OPTIONS_DEFINE=		IMAP MBSTRING SASL
IMAP_DESC=	Require PHP imap extension
MBSTRING_DESC=	Require PHP mbstring extension
SASL_DESC=	Support SASL Authentication

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MIMAP}
USE_PHP+=	imap
.endif

.if ${PORT_OPTIONS:MMBSTRING}
USE_PHP+=	mbstring
.endif

.if ${PORT_OPTIONS:MSASL}
RUN_DEPENDS+=	${PEARDIR}/Auth/SASL.php:${PORTSDIR}/security/pear-Auth_SASL
.endif

.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
