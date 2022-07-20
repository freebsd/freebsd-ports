PKGNAMESUFFIX=		-postfix

COMMENT=		mailman with postfix dependency

CONFLICTS_INSTALL=	mailman*exim* mailman-2* mailman-with-htdig-2*

OPTIONS_EXCLUDE=	COURIER EXIM4 OPENSMTPD SENDMAIL
OPTIONS_SLAVE=		POSTFIX

MASTERDIR=		${.CURDIR}/../../mail/mailman

.include "${MASTERDIR}/Makefile"
