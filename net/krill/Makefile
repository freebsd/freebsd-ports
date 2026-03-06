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
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR} \
		${STAGEDIR}/var/krill
	${INSTALL_DATA} ${WRKSRC}/defaults/krill.conf \
		${STAGEDIR}${PREFIX}/etc/krill/krill.conf.sample
	${INSTALL_MAN} ${krill.1.gz krillc.1.gz krillup.1.gz krillta.1.gz:L:S|^|${WRKSRC}/doc/|} \
		${STAGEDIR}${MANDIRS}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/krill.conf.5.gz \
		${STAGEDIR}${MANDIRS}/man5

.include <bsd.port.mk>
