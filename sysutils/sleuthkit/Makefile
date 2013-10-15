# Created by: Pieter Danhieux <opr@bsdaemon.be>
# $FreeBSD$

PORTNAME=	sleuthkit
PORTVERSION=	4.1.2
PORTREVISION=	1
CATEGORIES=	sysutils security
MASTER_SITES=	SF

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Tools and library for filesystem forensic analysis

LICENSE=	CPL IBM GPLv2
LICENSE_COMB=	multi
LICENSE_NAME_CPL=Common Public License
LICENSE_NAME_IBM=IBM Public License
LICENSE_FILE_CPL=${WRKSRC}/licenses/cpl1.0.txt
LICENSE_FILE_IBM=${WRKSRC}/licenses/IBM-LICENSE
LICENSE_PERMS_CPL=dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_IBM=dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	p5-DateTime-TimeZone>=0:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		exif:${PORTSDIR}/graphics/exif

CONFLICTS=	ja-ls-[0-9]* icat-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_PERL="${PERL}"
USES=		perl5
USE_LDCONFIG=	yes
DATADIR=	${PREFIX}/share/tsk

PORTDOCS=	NEWS.txt README.txt

OPTIONS_DEFINE=	DOCS LIBEWF
LIBEWF_DESC=	Build with EWF support
OPTIONS_DEFAULT=LIBEWF

LIBEWF_LIB_DEPENDS=	libewf.so:${PORTSDIR}/devel/libewf
LIBEWF_CONFIGURE_ON=	--with-libewf=${LOCALBASE}
LIBEWF_CONFIGURE_OFF=	--without-libewf

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
