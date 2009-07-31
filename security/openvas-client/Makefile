# New ports collection makefile for:	openvas-client
# Date created:		2008-04-27
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	openvas-client
PORTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/420/

MAINTAINER=	cherry@trombik.org
COMMENT=	A GUI client for OpenVAS

MAN1=		OpenVAS-Client.1 openvasclient-mkcert.1 openvasclient-mkrand.1

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20

.include "${.CURDIR}/../../security/openvas-libraries/Makefile.common"

.include <bsd.port.mk>
