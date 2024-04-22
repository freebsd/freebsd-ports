PORTNAME=	openrsync
PORTVERSION=	0.0.20200401
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Implementation of rsync with a BSD (ISC) license
WWW=		https://github.com/kristapsdz/openrsync

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USE_GITHUB=	yes
GH_ACCOUNT=	kristapsdz
GH_TAGNAME=	8b61216

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	MANDIR=${PREFIX}/share/man

PLIST_FILES=	bin/openrsync share/man/man1/openrsync.1.gz share/man/man5/openrsync.5.gz \
		share/man/man5/openrsyncd.5.gz

pre-build:
.for SUFFIX in rsync.5 rsyncd.5
	${MV} ${WRKSRC}/${SUFFIX} ${WRKSRC}/open${SUFFIX}
	${REINPLACE_CMD}	's|Nm rsync|Nm openrsync|g' ${WRKSRC}/open${SUFFIX}
	${REINPLACE_CMD}	's|rsync 5|openrsync 5|ig' ${WRKSRC}/open${SUFFIX}
	${REINPLACE_CMD}	's|rsyncd 5|openrsyncd 5|ig' ${WRKSRC}/open${SUFFIX}
.endfor
	${REINPLACE_CMD}	's|rsync.5|openrsync.5|g' ${WRKSRC}/Makefile
	${REINPLACE_CMD}	's|rsyncd.5|openrsyncd.5|g' ${WRKSRC}/Makefile
	${REINPLACE_CMD}	's|rsync 5|openrsync 5|ig' ${WRKSRC}/openrsync.1
	${REINPLACE_CMD}	's|rsyncd 5|openrsyncd 5|ig' ${WRKSRC}/openrsync.1

.include <bsd.port.mk>
