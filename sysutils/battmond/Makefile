# New ports collection makefile for:	battmond
# Date created:				16 June 2006
# Whom:					ntarmos@ceid.upatras.gr
#
# $FreeBSD$
#

PORTNAME=	battmond
PORTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://ntarmos.dyndns.org/Software/FreeBSD/

MAINTAINER=	ntarmos@ceid.upatras.gr
COMMENT=	A daemon monitoring the battery level of ACPI-enabled laptops

MAN1=		battmond.1
MANCOMPRESSED=	yes

PLIST_FILES=	sbin/battmond \
		etc/rc.d/battmond

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
IGNORE=		requires ACPI features present in FreeBSD 6.X and newer
.endif

.include <bsd.port.post.mk>
