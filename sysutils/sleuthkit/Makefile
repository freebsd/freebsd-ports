# Created by: Pieter Danhieux <opr@bsdaemon.be>
# $FreeBSD$

PORTNAME=	sleuthkit
PORTVERSION=	4.1.0
CATEGORIES=	sysutils security
MASTER_SITES=	SF

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Tools and library for filesystem forensic analysis

RUN_DEPENDS=	p5-DateTime-TimeZone>=0:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		exif:${PORTSDIR}/graphics/exif

CONFLICTS=	ja-ls-[0-9]* icat-[0-9]*

GNU_CONFIGURE=	yes
USES=		perl5
USE_LDCONFIG=	yes
DATADIR=	${PREFIX}/share/tsk
CPPFLAGS+=	-I${LOCALBASE}/include

PORTDOCS=	NEWS.txt README.txt
MAN1=		blkcalc.1 blkcat.1 blkls.1 \
		blkstat.1 ffind.1 fls.1 fsstat.1 hfind.1 icat.1 ifind.1 \
		ils.1 img_cat.1 img_stat.1 istat.1 jcat.1 jls.1 mactime.1 \
		mmls.1 mmstat.1 mmcat.1 sigfind.1 sorter.1 \
		tsk_comparedir.1 tsk_gettimes.1 tsk_loaddb.1 tsk_recover.1

OPTIONS_DEFINE=	DOCS LIBEWF
LIBEWF_DESC=	Build with EWF support
OPTIONS_DEFAULT=LIBEWF

LIBEWF_LIB_DEPENDS=	libewf.so:${PORTSDIR}/devel/libewf
LIBEWF_CONFIGURE_ON=	--with-libewf=${LOCALBASE}
LIBEWF_CONFIGURE_OFF=	--without-libewf

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
