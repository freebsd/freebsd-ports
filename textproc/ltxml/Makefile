# New ports collection makefile for:	LT XML
# Date created:		20 Oct 2000
# Whom:			Samuel Tardieu <sam@inf.enst.fr>
#
# $FreeBSD$
#

PORTNAME=	ltxml
PORTVERSION=	1.2
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cogsci.ed.ac.uk/pub/LTXML/

MAINTAINER=	sam@inf.enst.fr

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/XML

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-zlib
USE_GMAKE=	yes

post-install:
	strip ${PREFIX}/bin/sgmltoken
	strip ${PREFIX}/bin/unknit
	strip ${PREFIX}/bin/sgmlsb
	strip ${PREFIX}/bin/simple
	strip ${PREFIX}/bin/textonly
	strip ${PREFIX}/bin/simpleq
	strip ${PREFIX}/bin/sggrep
	strip ${PREFIX}/bin/sgcount
	strip ${PREFIX}/bin/sgmltrans
	strip ${PREFIX}/bin/getindex
	strip ${PREFIX}/bin/sgsort
	strip ${PREFIX}/bin/xmlnorm
	strip ${PREFIX}/bin/knit
	strip ${PREFIX}/bin/nslwhere
	strip ${PREFIX}/bin/pesis
	strip ${PREFIX}/bin/sgrpg
	strip ${PREFIX}/bin/nslshowddb
	strip ${PREFIX}/bin/intersect

MAN1=	ltxml.1 xmlnorm.1 pesis.1 sgcount.1 sggrep.1 \
	sgmlsb.1 sgmlseg.1 sgmltoken.1 sgmltrans.1 \
	sgrpg.1 textonly.1 unknit.1 sgsort.1 \
	nslwhere.1 knit.1 nslshowddb.1 getindex.1

MAN5=	ltxml-query.5

.include <bsd.port.mk>
