PORTNAME=	oddjob
DISTVERSION=	0.34.7
CATEGORIES=	sysutils
MASTER_SITES=	https://codeberg.org/freeipa/oddjob/archive/

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	D-Bus service that runs privileged jobs for client applications
WWW=		https://codeberg.org/freeipa/oddjob

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libxml2.so:textproc/libxml2

USES=		autoreconf gmake libtool pkgconfig
USE_RC_SUBR=	oddjobd
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--disable-systemd \
		--disable-sysvinit \
		--without-python \
		--without-selinux-labels \
		--without-selinux-acls \
		--disable-xml-docs

WRKSRC=		${WRKDIR}/oddjob

# sanity.sh is plain POSIX sh; drop the upstream /bin/bash shebang (which does
# not exist on FreeBSD and fails stage-qa) in favour of /bin/sh.
post-patch:
	@${REINPLACE_CMD} -e '1s|/bin/bash|/bin/sh|' ${WRKSRC}/src/sanity.sh

.include <bsd.port.mk>
