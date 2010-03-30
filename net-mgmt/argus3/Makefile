# New ports collection makefile for:	argus3
# Date created:		08 Jul 2006
# Whom:			Stefan Esser <se@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	argus
PORTVERSION=	3.0.2
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://qosient.com/argus/src/ \
		ftp://qosient.com/pub/argus/src/

MAINTAINER=	support@spectrum.ru
COMMENT=	A generic IP network transaction auditing tool

CONFLICTS=	argus-2* argus-sasl-2*

OPTIONS+=	SASL "SASL authentication support" on

USE_RC_SUBR=	argus

.include <bsd.port.options.mk>

USE_BISON=	build
GNU_CONFIGURE=	true

.if defined(WITH_SASL)
PKGNAMESUFFIX=	-sasl
LIB_DEPENDS+=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--with-sasl=${LOCALBASE}
.endif

MAN5=		argus.conf.5
MAN8=		argus.8

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/lib/sasl2#${LOCALBASE}/lib/sasl2#' ${WRKSRC}/argus/ArgusOutput.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/argus ${PREFIX}/sbin/argus
	${INSTALL_SCRIPT} ${WRKSRC}/bin/argusbug ${PREFIX}/bin/argusbug
	${MKDIR} ${EXAMPLESDIR}/Archive ${EXAMPLESDIR}/Config \
		 ${EXAMPLESDIR}/Deployment ${EXAMPLESDIR}/Startup \
		 ${EXAMPLESDIR}/System
.for i in README \
	Archive/argusarchive \
	Config/argus.conf \
	Deployment/sample \
	Startup/argus Startup/README \
	System/crontab System/magic
	${INSTALL_DATA} ${WRKSRC}/support/$i ${EXAMPLESDIR}/$i
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
.for i in README
	${INSTALL_DATA} ${WRKSRC}/doc/$i ${DOCSDIR}/
.endfor
.endif
.if !defined(NOMAN)
.for i in ${MAN5}
	${INSTALL_DATA} ${WRKSRC}/man/man5/$i ${MANPREFIX}/man/man5
.endfor
.for i in ${MAN8}
	${INSTALL_DATA} ${WRKSRC}/man/man8/$i ${MANPREFIX}/man/man8
.endfor
.endif

.include <bsd.port.post.mk>
