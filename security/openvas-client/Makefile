# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME=	openvas-client
PORTVERSION=	2.0.4
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/595/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI client for OpenVAS

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_GNOME=	gtk20

MAKE_JOBS_UNSAFE=yes

.include "${.CURDIR}/../../security/openvas-libraries/Makefile.common"

.include <bsd.port.mk>
