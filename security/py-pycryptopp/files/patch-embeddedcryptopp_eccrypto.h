--- embeddedcryptopp/eccrypto.h.orig	2010-09-21 04:36:16.000000000 +0000
+++ embeddedcryptopp/eccrypto.h
@@ -43,7 +43,7 @@ public:
 	void Initialize(const EllipticCurve &ec, const Point &G, const Integer &n, const Integer &k = Integer::Zero())
 	{
 		this->m_groupPrecomputation.SetCurve(ec);
-		SetSubgroupGenerator(G);
+		this->SetSubgroupGenerator(G);
 		m_n = n;
 		m_k = k;
 	}
@@ -145,9 +145,9 @@ public:
 	typedef typename EC::Point Element;
 
 	void Initialize(const DL_GroupParameters_EC<EC> &params, const Element &Q)
-		{this->AccessGroupParameters() = params; SetPublicElement(Q);}
+		{this->AccessGroupParameters() = params; this->SetPublicElement(Q);}
 	void Initialize(const EC &ec, const Element &G, const Integer &n, const Element &Q)
-		{this->AccessGroupParameters().Initialize(ec, G, n); SetPublicElement(Q);}
+		{this->AccessGroupParameters().Initialize(ec, G, n); this->SetPublicElement(Q);}
 
 	// X509PublicKey
 	void BERDecodePublicKey(BufferedTransformation &bt, bool parametersPresent, size_t size);
@@ -166,9 +166,9 @@ public:
 	void Initialize(const EC &ec, const Element &G, const Integer &n, const Integer &x)
 		{this->AccessGroupParameters().Initialize(ec, G, n); this->SetPrivateExponent(x);}
 	void Initialize(RandomNumberGenerator &rng, const DL_GroupParameters_EC<EC> &params)
-		{GenerateRandom(rng, params);}
+		{this->GenerateRandom(rng, params);}
 	void Initialize(RandomNumberGenerator &rng, const EC &ec, const Element &G, const Integer &n)
-		{GenerateRandom(rng, DL_GroupParameters_EC<EC>(ec, G, n));}
+		{this->GenerateRandom(rng, DL_GroupParameters_EC<EC>(ec, G, n));}
 
 	// PKCS8PrivateKey
 	void BERDecodePrivateKey(BufferedTransformation &bt, bool parametersPresent, size_t size);
