# New ports collection makefile for:	crm114
# Date created:				23 February 2004
# Whom:					Meno Abels <meno.abels@adviser.com>
#
# $FreeBSD$
#

PORTNAME=	crm114
PORTVERSION=	20040212
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	crm114
DISTNAME=	${PORTNAME}-${PORTVERSION}-BlameJetlag.src

MAINTAINER=	Meno.Abels@Adviser.com
COMMENT=	An Markov based SpamFilter

LIB_DEPENDS=	tre.4:${PORTSDIR}/textproc/libtre

USE_GETTEXT=	yes
USE_ICONV=	yes

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" prefix="${PREFIX}" \
		LDFLAGS="${LDFLAGS}" LIBS="${LIBS}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-L${LOCALBASE}/lib -liconv -lintl

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in CRM114_Mailfilter_HOWTO.txt FAQ.txt INTRO.txt QUICKREF.txt README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
