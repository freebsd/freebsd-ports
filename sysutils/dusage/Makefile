# New ports collection makefile for:	dusage
# Date created:				22 January 2006
# Whom:					Jeffrey H. Johnson <CPE1704TKS@bellsouth.net>
#
# $FreeBSD$
#

PORTNAME=	dusage
PORTVERSION=	19900227
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.unicamp.br/pub/unix-c/sysadmin/ \
		http://ftp.br.xemacs.org/pub/unix-c/sysadmin/
DISTNAME=	dusage
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	CPE1704TKS@bellsouth.net
COMMENT=	Report about disk space in use, change since last run, etc

BROKEN=		Unfetchable

NO_BUILD=	yes
USE_PERL5=	yes

NO_CDROM=	may not be sold
RESTRICTED=	may not be used to harm any living creature including the world and the universe

ALL_TARGET=	${PORTNAME}
MAN1=		dusage.1
PLIST_FILES=	bin/dusage

.include <bsd.port.mk>
