# New ports collection makefile for:	mail/dcc-dccd
# Date created:		Wed Oct 9 19:30:00 WST 2002
# Whom:			Dean Hollister <dean@odyssey.apana.org.au>
#
# $FreeBSD$
#

PORTNAME=	dcc-dccd
PORTVERSION=	1.2.28
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.rhyolite.com/anti-spam/dcc/source/ \
		http://www.wa.apana.org.au/~dean/sources/ \
		ftp://ftp.wa.apana.org.au/pub/pc/unix/packages/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dean@odyssey.apana.org.au
COMMENT=	Distributed Checksum Clearinghouse procmail, sendmail support

USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}/dcc
MANCOMPRESSED=	yes
MAN8=		cdcc.8		dcc.8		dccd.8 \
		dccm.8		dccproc.8	dccsight.8 \
		dccifd.8	dbclean.8	dblist.8

.if exists(/usr/lib/libmilter.a) || exists(${LOCALBASE}/lib/libmilter.a)
PLIST_SUB+=	WITH_SENDMAIL=""
.else
CONFIGURE_ARGS+=	--disable-dccm --disable-dccifd
PLIST_SUB+=	WITH_SENDMAIL="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502102
FORBIDDEN=	"Links against conflicting thread libraries"
.endif

post-patch:
	${FIND} ${WRKSRC} -type f -exec \
		${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' {} \;
	${REINPLACE_CMD} -e 's,-pthread,${PTHREAD_LIBS},g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
