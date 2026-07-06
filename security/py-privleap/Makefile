PORTNAME=	privleap
DISTVERSION=	5.9-1
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Limited Privilege Escalation Framework
WWW=		https://www.kicksecure.com/wiki/Privleap

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PAM>=0:security/py-PAM@${PY_FLAVOR}

USES=		python:3.13+ shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	Kicksecure
USE_RC_SUBR=	privleapd

SHEBANG_FILES=	usr/bin/* usr/libexec/privleap/shim.py

NO_ARCH=	yes

SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

do-build:
	@${PYTHON_CMD} -OO ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHON_SITELIBDIR} \
		-f ${WRKSRC}/usr/lib/python3/dist-packages/${PORTNAME}

do-install:
.for script in leapctl leaprun privleapd
	${INSTALL_SCRIPT} ${WRKSRC}/usr/bin/${script} ${STAGEDIR}${PREFIX}/bin/${script}
.endfor
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
	@cd ${WRKSRC}/usr/lib/python3/dist-packages/${PORTNAME} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/usr/libexec/${PORTNAME}/shim.py ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_SCRIPT} ${FILESDIR}/pam_create_socket.sh ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/auto-generated-man-pages/leapctl.8 ${STAGEDIR}${PREFIX}/share/man/man8
	${INSTALL_MAN} ${WRKSRC}/auto-generated-man-pages/leaprun.8 ${STAGEDIR}${PREFIX}/share/man/man8
	${INSTALL_MAN} ${WRKSRC}/auto-generated-man-pages/privleap.conf.d.5 ${STAGEDIR}${PREFIX}/share/man/man5
	${INSTALL_MAN} ${WRKSRC}/auto-generated-man-pages/privleapd.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${ETCDIR}/conf.d
	@cd ${WRKSRC}/etc/${PORTNAME}/conf.d && ${COPYTREE_SHARE} . ${STAGEDIR}${ETCDIR}/conf.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/pam.d
	${INSTALL_DATA} ${FILESDIR}/pam.conf ${STAGEDIR}${PREFIX}/etc/pam.d/privleapd

.include <bsd.port.mk>
