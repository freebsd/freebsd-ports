PORTNAME=	krill
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.5
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	RPKI daemon, Certificate Authority and Publication Server
WWW=		https://github.com/NLnetLabs/krill

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	ring crate not ported to other architectures

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	NLnetLabs

USE_RC_SUBR=	${PORTNAME}

# SUB_FILES=	pkg-message
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/krill
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/krillc
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/krillta
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/krillup
	@${MKDIR} ${STAGEDIR}/${PREFIX}/etc/krill
	${INSTALL_DATA} ${WRKSRC}/defaults/krill.conf \
		${STAGEDIR}${PREFIX}/etc/krill/krill.conf.sample
	${INSTALL_MAN} ${WRKSRC}/doc/krill.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/krillc.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/krillup.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/defaults/krill.conf \
		${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}/var/krill

.include <bsd.port.mk>
