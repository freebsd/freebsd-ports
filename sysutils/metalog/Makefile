# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	metalog
DISTVERSION=	0.8
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/old

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modern syslogd replacement with PCRE support

LICENSE=	GPLv2

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

USE_BZIP2=	yes
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN5=		metalog.conf.5
MAN8=		metalog.8
PORTDOCS=	AUTHORS NEWS README
PORTEXAMPLES=	metalog.conf
PLIST_FILES=	sbin/metalog

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|' ${WRKSRC}/man/*[58]

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/,} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
