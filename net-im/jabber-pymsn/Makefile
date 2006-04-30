# New ports collection makefile for:	Jabber Python MSN Transport
# Date created:				Tue Nov 23 16:42:07 CET 2004
# Whom:					Martijn Lina <martijn@pacno.net>
#
# $FreeBSD$

PORTNAME=	pymsn
PORTVERSION=	0.11a
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://msn-transport.jabberstudio.org/tarballs/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
PKGNAMEPREFIX=	jabber-
PKGNAMESUFFIX=	-transport
DISTNAME=	${PORTNAME}t-${PORTVERSION}
DIST_SUBDIR=	jabber

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Python MSN-Transport for Jabber

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/OpenSSL/__init__.py:${PORTSDIR}/security/py-openssl \
		${PYTHON_SITELIBDIR}/twisted/__init__.py:${PORTSDIR}/devel/py-twisted \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging

WRKSRC=		${WRKDIR}/${PORTNAME}t-0.11

OPTIONS=	EJABBERD "Use transport with ejabberd" off

NO_BUILD=	yes
USE_PYTHON=	yes
USE_RC_SUBR=	jabber-pymsn-transport.sh

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

INST_DIR=	${PREFIX}/lib/jabber/${PORTNAME}

PORTDOCS=	COPYING README TODO

.include <bsd.port.pre.mk>

.if defined(WITH_EJABBERD)
JABBER_USER?=	ejabberd
SUB_LIST+=	JABBER_REQUIRE=ejabberd
.else
JABBER_USER?=	jabber
SUB_LIST+=	JABBER_REQUIRE=jabberd
.endif

SUB_LIST+=	JABBER_USER=${JABBER_USER}

post-extract:
	@${FIND} ${WRKSRC}/ -type d \( -name CVS -or -name .svn \) | ${XARGS} ${RM} -rf

post-patch:
	@${REINPLACE_CMD} -i "" -e '/spooldir/s|/path/to/data|/var/spool/jabber|' \
				-e 's|PyMSNt.pid|/var/jabberd/pid/PyMSNt.pid|' \
		${WRKSRC}/config-example.xml
	@${REINPLACE_CMD} -i "" 's|../config.xml|${PREFIX}/etc/jabber-pymsn.xml|g' \
		${WRKSRC}/src/xmlconfig.py
	@${REINPLACE_CMD} -i "" -e 's|spooldir = ""|spooldir = "/var/spool/jabber"|g' \
				-e 's|pid = ""|pid = "/var/jabberd/pid/PyMSNt.pid"|g' \
		${WRKSRC}/src/config.py
	@${REINPLACE_CMD} -i "" 's|"config.xml"|"${PREFIX}/etc/jabber-pymsn.xml"|' \
		${WRKSRC}/src/main.py
	@${REINPLACE_CMD} -i "" 's|#!/usr/bin/python|#!${PYTHON_CMD}|' \
		${WRKSRC}/PyMSNt.py
	@${RM} -f ${WRKSRC}/src/*.orig

do-install:
	${MKDIR} ${INST_DIR}/src ${INST_DIR}/data
	${INSTALL_SCRIPT} ${WRKSRC}/PyMSNt.py ${INST_DIR}
	${INSTALL_DATA} ${WRKSRC}/data/defaultJabberAvatar.png ${INST_DIR}/data
	${INSTALL_DATA} ${WRKSRC}/data/defaultMSNAvatar.png ${INST_DIR}/data
	@${CP} -Rv ${WRKSRC}/src/* ${INST_DIR}/src/
	@${FIND} ${INST_DIR}/src/ -type d -exec ${CHMOD} 755 "{}" \;
	@${FIND} ${INST_DIR}/src/ -type f -exec ${CHMOD} 644 "{}" \;
	${MKDIR} ${EXAMPLESDIR}/etc
	${INSTALL_DATA} ${WRKSRC}/config-example.xml ${EXAMPLESDIR}/etc/jabber-pymsn.xml
	@[ -f ${PREFIX}/etc/jabber-pymsn.xml ] || ${CP} -v ${EXAMPLESDIR}/etc/jabber-pymsn.xml ${PREFIX}/etc/jabber-pymsn.xml
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for portdoc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${portdoc} ${DOCSDIR}/
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
