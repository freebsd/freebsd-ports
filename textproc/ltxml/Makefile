# New ports collection makefile for:	LT XML
# Date created:		20 Oct 2000
# Whom:			Samuel Tardieu <sam@inf.enst.fr>
#
# $FreeBSD$
#

PORTNAME=	ltxml
PORTVERSION=	1.2.5
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cogsci.ed.ac.uk/pub/LTXML/

MAINTAINER=	sam@inf.enst.fr

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/XML

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-zlib --enable-multi-byte
USE_GMAKE=	yes

post-install:
	${STRIP_CMD} ${PREFIX}/bin/unknit
	${STRIP_CMD} ${PREFIX}/bin/sgmlsb
	${STRIP_CMD} ${PREFIX}/bin/simple
	${STRIP_CMD} ${PREFIX}/bin/textonly
	${STRIP_CMD} ${PREFIX}/bin/simpleq
	${STRIP_CMD} ${PREFIX}/bin/sggrep
	${STRIP_CMD} ${PREFIX}/bin/sgcount
	${STRIP_CMD} ${PREFIX}/bin/sgmltrans
	${STRIP_CMD} ${PREFIX}/bin/getindex
	${STRIP_CMD} ${PREFIX}/bin/sgsort
	${STRIP_CMD} ${PREFIX}/bin/xmlnorm
	${STRIP_CMD} ${PREFIX}/bin/knit
	${STRIP_CMD} ${PREFIX}/bin/nslwhere
	${STRIP_CMD} ${PREFIX}/bin/pesis
	${STRIP_CMD} ${PREFIX}/bin/sgrpg
	${STRIP_CMD} ${PREFIX}/bin/nslshowddb
	${STRIP_CMD} ${PREFIX}/bin/intersect

MAN1=	ltxml.1 xmlnorm.1 pesis.1 sgcount.1 sggrep.1 \
	sgmlsb.1 sgmlseg.1 sgmltoken.1 sgmltrans.1 \
	sgrpg.1 textonly.1 unknit.1 sgsort.1 \
	nslwhere.1 knit.1 nslshowddb.1 getindex.1

MAN5=	ltxml-query.5

.include <bsd.port.mk>
