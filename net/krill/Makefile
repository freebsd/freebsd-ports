PORTNAME=	krill
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.0
CATEGORIES=	net

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	RPKI daemon, Certificate Authority and Publication Server
WWW=		https://github.com/NLnetLabs/krill

LICENSE=	MPL20
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
	@${MKDIR} ${STAGEDIR}${ETCDIR} \
		${STAGEDIR}/var/krill
	${INSTALL_DATA} ${WRKSRC}/defaults/krill.conf \
		${STAGEDIR}${ETCDIR}/krill.conf.sample
.for f in krill.1 krillc.1 krillup.1 krillta.1 krill.conf.5
	${INSTALL_MAN} ${WRKSRC}/doc/${f}.gz \
		${STAGEDIR}${MANDIRS}/man${f:E}
.endfor

.include <bsd.port.mk>
