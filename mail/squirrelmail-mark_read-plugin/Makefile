PORTNAME=	mark_read
PORTVERSION=	1.4.2
PORTREVISION=	4
CATEGORIES=	mail www
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}-1.2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provides one-click link to mark read/unread all mails in a folder

USE_SM_COMPAT=	YES

SQUIRREL_PLUGIN_NAME=	${PORTNAME:S/-/_/}

post-patch:
	@${RM} ${WRKSRC}/${SQUIRREL_PLUGIN_NAME}/mark_read.php.orig

.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.mk>
