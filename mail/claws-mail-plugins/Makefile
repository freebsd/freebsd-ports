# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD$

PORTNAME=	claws-mail-plugins
PORTVERSION=	3.17
CATEGORIES=	mail news

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	claws-mail plugins meta-port

LICENSE=	BSD2CLAUSE

USES=		metaport

.include "../claws-mail/Makefile.claws.plugins"

# pgpcore, pgpinline, pgpmime, smime
CLAWS_PLUGINS+=	pgp

.for _addon in ${CLAWS_PLUGINS:O}
. if exists(../claws-mail-${_addon})
OPTIONS_DEFINE+=	${_addon:tu}
${_addon:tu}_DESC!=	${MAKE} -C ../claws-mail-${_addon} -V COMMENT
. endif
.endfor

.include <bsd.port.options.mk>

.for _addon in ${CLAWS_PLUGINS}
. if ${PORT_OPTIONS:M${_addon:tu}} != ""
RUN_DEPENDS+=	claws-mail-${_addon}>=0:mail/claws-mail-${_addon}
. endif
.endfor

.include <bsd.port.mk>
