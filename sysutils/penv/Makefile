# New ports collection makefile for:	penv
# Date created:		5 August 2001
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	penv
PORTVERSION=	1.2p1
CATEGORIES=	sysutils
MASTER_SITES=	http://devel.ringlet.net/sysutils/penv/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/pre/}

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Set the environment according to the current working directory

RUN_DEPENDS=	envdir:${PORTSDIR}/sysutils/daemontools

MAN1=		penv.1
MANCOMPRESSED=	yes

CFLAGS_COMPAT=	-DHAVE_STRLCPY -DHAVE_FGETLN
MAKE_ENV+=	CFLAGS_COMPAT="${CFLAGS_COMPAT}"

.if		!defined(NO_RELEASE)
MAKE_ENV+=	RELEASE=yes
.endif

DBDIR?=		/var/db/${PORTNAME}

PLIST_SUB+=	DBDIR=${DBDIR}

DOCS=		html txt

post-install:
		${MKDIR} ${PREFIX}/etc
		${MKDIR} ${DBDIR}
		${INSTALL_DATA} ${WRKSRC}/penv.conf.default ${PREFIX}/etc
		if [ ! -e ${PREFIX}/etc/penv.conf ]; then \
			${INSTALL_DATA} ${WRKSRC}/penv.conf.default \
				${PREFIX}/etc/penv.conf; \
		fi
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		cd ${WRKSRC}/doc && ${TAR} -cpf - ${DOCS} | ${TAR} -xpf - -C ${DOCSDIR}
.endif

.include <bsd.port.mk>
