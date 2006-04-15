# New ports collection makefile for:	instiki
# Date created:				4 January 2005
# Whom:					Kelley Reynolds <kelley@insidesystems.net>
#
# $FreeBSD$
#

PORTNAME=	instiki
PORTVERSION=	0.10.2
PORTREVISION=	2
CATEGORIES=	www ruby
MASTER_SITES=	http://rubyforge.lauschmusik.de/instiki/	\
		http://rubyforge.planetargon.com/instiki/	\
		http://rubyforge.rubyuser.de/instiki/
EXTRACT_SUFX=	.tgz

MAINTAINER=	arsptr@optusnet.com.au
COMMENT=	Easy to set up wiki clone implemented in ruby

NO_BUILD=	yes
USE_RUBY=	yes
USE_RUBY_FEATURES=	1.8
INSTIKIDIR?=	instiki

PLIST_SUB=	INSTIKIDIR=${INSTIKIDIR}/

USE_RC_SUBR=	${PORTNAME}
SED_LIST+=	-e 's,%%INSTIKIDIR%%,${INSTIKIDIR},g' \
		-e 's,%%INSTIKIPORT%%,${INSTIKIPORT},g' \
		-e 's,%%RUBY_WITH_SUFFIX%%,${RUBY_WITH_SUFFIX},g'

RUBY_SHEBANG_FILES=instiki

INSTIKIPORT?=	2500

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
	${CP} -pR ${WRKSRC}/ ${PREFIX}/${INSTIKIDIR}
	${MKDIR} ${PREFIX}/${INSTIKIDIR}/storage/${INSTIKIPORT}
	${CHMOD} +x ${PREFIX}/${INSTIKIDIR}/instiki

.include <bsd.port.mk>
