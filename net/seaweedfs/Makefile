PORTNAME=	seaweedfs
DISTVERSION=	2.40
CATEGORIES=	net sysutils

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Distributed Object Store and Filesystem

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
USE_GITLAB=	nodefault
GH_ACCOUNT=	chrislusf

.include "Makefile.deps"

post-build:
.for cfg in master filer security replication notification
	${WRKDIR}/bin/weed scaffold -config ${cfg} -output ${WRKDIR}/
.endfor

post-install:
	${MKDIR} \
	    ${STAGEDIR}/var/db/${PORTNAME} \
	    ${STAGEDIR}/var/log/${PORTNAME} \
	    ${STAGEDIR}${ETCDIR}
.for cfg in master filer security replication notification
	${INSTALL_DATA} ${WRKDIR}/${cfg}.toml \
	    ${STAGEDIR}${ETCDIR}/${cfg}.toml.sample
.endfor

GO_TARGET=	./weed:${PREFIX}/sbin/weed
CGO_CFLAGS=	-I.

USE_RC_SUBR=	seaweedfs

USERS=		seaweedfs
GROUPS=		seaweedfs

SUB_FILES=	pkg-message

.include	<bsd.port.mk>
