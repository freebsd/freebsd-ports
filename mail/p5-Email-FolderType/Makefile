# New ports collection makefile for:	p5-Email-FolderType
# Date created:				August 31 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Email-FolderType
PORTVERSION=	0.7
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Determine the type of a mail folder

PERL_CONFIGURE=	yes

MAN3=		Email::FolderType.3 \
		Email::FolderType::Local.3 \
		Email::FolderType::Register.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500503
EXTRA_PATCHES=	${PATCHDIR}/5.005-t::05_register.t

# make PREFIX-clean under perl 5.005_03
post-configure:
	${PERL} -pi -e 's,/usr/local/,\$$(PREFIX)/,g' ${WRKSRC}/Makefile

.endif

.include <bsd.port.post.mk>
