PORTNAME=	ca-certificates
PORTVERSION=	2024.2.69
DISTVERSIONSUFFIX=	_v8.0.303-91.4.el9_4
PORTREVISION=	3
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Mozilla CA root certificate bundle (Rocky Linux ${LINUX_DIST_VER})

LICENSE=	PD

USES=		linux:rl9
USE_LINUX=	p11-kit
USE_LINUX_RPM=	noarch

OPTIONS_DEFINE=	DOCS

post-stage:
	cd ${STAGEDIR} && ${LINUXBASE}/bin/sh \
		./${PREFIX}/usr/bin/update-ca-trust extract \
		-o ./${PREFIX}/etc/pki/ca-trust/extracted
	${FIND} ${STAGEDIR}${PREFIX} -type l -exec \
		${SH} -c "tgt=\$$(readlink {}) ; [ \$$tgt != \$${tgt#/} ] && ${RLN} ${STAGEDIR}${PREFIX}\$$tgt {}" \; || ${TRUE}
	cd ${STAGEDIR}${PREFIX} && \
		${FIND} etc/pki/ca-trust/extracted/pem/directory-hash -type f -or -type l >> ${TMPPLIST}


.include <bsd.port.mk>
