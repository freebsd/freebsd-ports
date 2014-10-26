# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	maildirsync
PORTVERSION=	1.2
CATEGORIES=	mail perl5
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Online synchronizer for Maildir-format mailboxes

USES=		perl5 shebangfix

SHEBANG_FILES=	maildirsync.pl

OPTIONS_DEFINE=	EXAMPLES

do-build:
	pod2man ${WRKSRC}/maildirsync.pod > ${WRKSRC}/maildirsync.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/maildirsync.pl \
		${STAGEDIR}${PREFIX}/bin/maildirsync
	${INSTALL_MAN} ${WRKSRC}/maildirsync.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/sample.sh ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/mailbalance
.for d in lib log trashbags
	${RM} -rf ${WRKSRC}/contrib/mailbalance-0.2.0/${d}
.endfor
	${INSTALL_DATA} ${WRKSRC}/contrib/mailbalance-0.2.0/* \
		${STAGEDIR}${EXAMPLESDIR}/mailbalance

.include <bsd.port.pre.mk>

.if ${PERL_VER} >= 5.18
BROKEN=		Does not build with Perl 5.18 or above
.endif

.include <bsd.port.post.mk>
