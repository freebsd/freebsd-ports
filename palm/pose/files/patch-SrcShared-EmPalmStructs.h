--- ../SrcShared/EmPalmStructs.h.orig	Thu Oct  5 15:19:20 2006
+++ ../SrcShared/EmPalmStructs.h	Thu Oct  5 15:19:43 2006
@@ -577,9 +577,9 @@
 	template <class A>																\
 	INLINE_ EmAlias##type<A>& EmAlias##type<A>::operator= (rhs_type val)			\
 	{																				\
-		if (sizeof (asType) == 1)		A::PutByte (this->GetPtr (), (unsigned char) (asType) val);		\
-		else if (sizeof (asType) == 2)	A::PutWord (this->GetPtr (), (unsigned short) (asType) val);	\
-		else if (sizeof (asType) == 4)	A::PutLong (this->GetPtr (), (unsigned long) (asType) val);		\
+		if (sizeof (asType) == 1)		A::PutByte (this->GetPtr (), (unsigned char) (asType) (long) val);		\
+		else if (sizeof (asType) == 2)	A::PutWord (this->GetPtr (), (unsigned short) (asType) (long) val);	\
+		else if (sizeof (asType) == 4)	A::PutLong (this->GetPtr (), (unsigned long) (asType) (long) val);		\
 		else BadSetter ();															\
 																					\
 		return *this;																\
@@ -589,9 +589,9 @@
 																					\
 	INLINE_ EmProxy##type& EmProxy##type::operator= (rhs_type val)					\
 	{																				\
-		if (sizeof (asType) == 1)		LAS::PutByte (this->GetPtr (), (unsigned char) (asType) val);	\
-		else if (sizeof (asType) == 2)	LAS::PutWord (this->GetPtr (), (unsigned short) (asType) val);	\
-		else if (sizeof (asType) == 4)	LAS::PutLong (this->GetPtr (), (unsigned long) (asType) val);	\
+		if (sizeof (asType) == 1)		LAS::PutByte (this->GetPtr (), (unsigned char) (asType) (long) val);	\
+		else if (sizeof (asType) == 2)	LAS::PutWord (this->GetPtr (), (unsigned short) (asType) (long) val);	\
+		else if (sizeof (asType) == 4)	LAS::PutLong (this->GetPtr (), (unsigned long) (asType) (long) val);	\
 		else BadSetter ();															\
 																					\
 		return *this;																\
