# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME=	openvas-client
PORTVERSION=	2.0.4
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/595/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GUI client for OpenVAS

MAN1=		OpenVAS-Client.1 openvasclient-mkcert.1

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_GNOME=	gtk20

NO_STAGE=	yes
.include "${.CURDIR}/../../security/openvas-libraries/Makefile.common"

.include <bsd.port.mk>
