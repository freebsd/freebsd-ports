# ex:ts=8
# Ports collection makefile for:	ccrypt
# Date created:			Feb 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ccrypt
PORTVERSION=	1.8
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
				http://www.mathstat.dal.ca/~selinger/ccrypt/download/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	corky1951@comcast.net
COMMENT=	A command-line utility for encrypting and decrypting files and streams

.if !defined(WITHOUT_NLS)
USE_GNOME=		intltool
USE_GETTEXT=	yes
PLIST_SUB+=		NLS=""
.else
USE_PERL5_BUILD=	yes
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

GNU_CONFIGURE=	yes

MAN1=	ccrypt.1
MLINKS=	ccrypt.1 ccencrypt.1 \
	ccrypt.1 ccdecrypt.1 \
	ccrypt.1 ccat.1

post-patch:
	@${REINPLACE_CMD} -e 's|gtar|tar|g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README doc/ccrypt.html doc/cypfaq01.txt
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
