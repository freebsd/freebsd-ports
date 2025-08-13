PORTNAME=	bash-completion-zfs
DISTVERSION=	2.3.3
CATEGORIES=	shells
# Use direct link to 15KB file instead of 30+MB tarball:
# https://github.com/openzfs/zfs/releases/download/zfs-${DISTVERSION}/zfs-${DISTVERSION}.tar.gz
MASTER_SITES=	https://raw.githubusercontent.com/openzfs/zfs/refs/tags/zfs-${DISTVERSION}/contrib/bash_completion.d/
DISTNAME=	zfs.in
EXTRACT_SUFX=	#
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	OpenZFS extension to the Bash completion library
WWW=		https://github.com/openzfs/zfs/

LICENSE=	MIT

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	${WRKSRC}

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	etc/bash_completion.d/zfs

post-patch:
	${REINPLACE_CMD} -e 's|@sbindir@|/sbin|g' ${WRKSRC}/${DISTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME} \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/zfs

.include <bsd.port.mk>
