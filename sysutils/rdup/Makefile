# ex:ts=8
# Ports collection makefile for:	rdup
# Date created:			Jun 11, 2009
# Whom:				corky1951@comcast.net
#
# $FreeBSD$
#

PORTNAME=	rdup
PORTVERSION=	1.1.7
CATEGORIES=	sysutils
MASTER_SITES=	http://miek.nl/projects/rdup/

MAINTAINER=	corky1951@comcast.net
COMMENT=	A tool to generate an (incremental) backup file list

LIB_DEPENDS=	glib-2.0:${PORTSDIR}/devel/glib20 \
		pcre:${PORTSDIR}/devel/pcre \
		archive:${PORTSDIR}/archivers/libarchive \
		nettle:${PORTSDIR}/security/nettle

USE_BZIP2=	yes

USE_AUTOTOOLS=	autoconf:262
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib ${LDFLAGS}"

USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

PLIST_FILES=	bin/rdup \
		bin/rdup-simple \
		bin/rdup-tr \
		bin/rdup-up

MAN1=		rdup.1 \
		rdup-tr.1 \
		rdup-up.1

MAN7=		rdup-backups.7

.include <bsd.port.mk>
